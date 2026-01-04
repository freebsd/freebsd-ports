# sets dbus daemon up for testing
#
# Feature:	dbus-testing
# Usage:	USES=dbus-testing
#
# MAINTAINER:	arrowd@FreeBSD.org

.if !defined(_INCLUDE_USES_DBUS_TESTINGS_MK)
_INCLUDE_USES_DBUS_TESTINGS_MK=yes

TEST_DEPENDS+=	dbus-launch:devel/dbus
TEST_ENV+=	DBUS_SESSION_BUS_ADDRESS=unix:path=${_SESSION_BUS_SOCKET}

_DBUS_LAUNCH?=	${LOCALBASE}/bin/dbus-launch

_DBUS_LOCAL_CONF_SRC=	${PORTSDIR}/Templates/dbus-testing-system-local.conf
_DBUS_LOCAL_CONF_DST=	${LOCALBASE}/etc/dbus-1/system-local.conf

_ALREADY_STARTED_COOKIE=${WRKDIR}/.dbus-testing-was-already-running
_SESSION_BUS_SOCKET=	${WRKDIR}/.dbus-session-bus-socket
_SESSION_BUS_PIDFILE=	${WRKDIR}/.dbus-session-bus-pid

_USES_test=	299:dbus-testing-pre-test \
		801:dbus-testing-post-test

dbus-testing-pre-test:
	@${ECHO_CMD} "===> Starting dbus testing instances"
.  if defined(PACKAGE_BUILDING) && ${UID} == 0
# When running in Poudriere we can afford installing a permissive config
# that allows anyone to own any D-Bus name. This is useful for running tests
# without prior "make install".
	${INSTALL_DATA} ${_DBUS_LOCAL_CONF_SRC} ${_DBUS_LOCAL_CONF_DST}
.  endif
# Start the system bus via rc script
	@(/usr/sbin/service dbus onestatus && \
		${TOUCH} ${_ALREADY_STARTED_COOKIE}) || ${TRUE}
	@/usr/sbin/service dbus onestart || ${TRUE}
# Now start an isolated session bus. This is complicated because 'make test'
# wraps everything into ${SETENVI}, so we can't easily pass the bus address via
# environment. Instead we put the bus' socket under a well-known path
# ${_SESSION_BUS_SOCKET} and pass it to make via usual ${TEST_ENV}.
# Typical value for DBUS_SESSION_BUS_ADDRESS looks like
# unix:path=/tmp/dbus-xZF47bxeMf,guid=227e19aaa3a87a1bbdb96cd56901b7e0
	@session_bus_env=$$(${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${_DBUS_LAUNCH} | ${XARGS}) ; \
	session_bus_sock=$$(echo $$session_bus_env | grep -o 'path=.*' | sed -e 's|path=||' -e 's|,.*||') ; \
	${LN} -fs $$session_bus_sock ${_SESSION_BUS_SOCKET} ;\
	${SETENVI} $$session_bus_env ${SH} -c 'echo $$DBUS_SESSION_BUS_PID' > ${_SESSION_BUS_PIDFILE}

dbus-testing-post-test:
	@${ECHO_CMD} "===> Stopping dbus testing instances"
	@(${CAT} ${_SESSION_BUS_PIDFILE} | ${XARGS} kill) || ${TRUE}
	@${RM} ${_SESSION_BUS_SOCKET} ${_SESSION_BUS_PIDFILE}
	@[ ! -f ${_ALREADY_STARTED_COOKIE} ] && \
		/usr/sbin/service dbus onestop || ${TRUE}
	@${RM} ${_ALREADY_STARTED_COOKIE}
.  if defined(PACKAGE_BUILDING) && ${UID} == 0
	${RM} ${_DBUS_LOCAL_CONF_DST}
.  endif

.endif
