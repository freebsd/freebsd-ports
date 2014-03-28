# $FreeBSD$
#
# Feature:	qmail
# Usage:	USES=qmail or USES=qmail:ARGS
# Valid ARGS:	both (default, implicit), run, build, vars
#
# Ports can use the following vars:
#
# QMAIL_PREFIX		- Define it if qmail is installed in a different PREFIX.
#			  Default: /var/qmail
#
# QMAIL_SLAVEPORT	- Define it if you install a slaveport of qmail, to
#			  prevent stale dependencies. Valid slaveports are:
#			  ldap, mysql, spamcontrol and tls.
#
# MAINTAINER=	bdrewery@FreeBSD.org

.if !defined(_INCLUDE_QMAIL_MK)
_INCLUDE_QMAIL_MK=	yes

QMAIL_PREFIX?=	/var/qmail

.if !defined(qmail_ARGS)
qmail_ARGS=	both
.endif

.if ${qmail_ARGS} == "build"
BUILD_DEPENDS+=	${_QMAIL_DEPENDS}
.elif ${qmail_ARGS} == "run"
RUN_DEPENDS+=	${_QMAIL_DEPENDS}
.elif ${qmail_ARGS} == "both"
BUILD_DEPENDS+=	${_QMAIL_DEPENDS}
RUN_DEPENDS+=	${_QMAIL_DEPENDS}
.elif ${qmail_ARGS} == "vars"
.else
IGNORE=	USES=qmail - invalid args: [${qmail_ARGS}] specified
.endif

.if ${qmail_ARGS} != "vars"

_QMAIL_VALID_SLAVEPORTS=	ldap mysql spamcontrol tls

.  if defined(QMAIL_SLAVEPORT)
.    for slave in ${_QMAIL_VALID_SLAVEPORTS}
.      if ${QMAIL_SLAVEPORT:L} == ${slave}
_QMAIL_SLAVEPORT_OKAY=	true
.      endif
.    endfor

.    if !defined(_QMAIL_SLAVEPORT_OKAY)
IGNORE=	Invalid QMAIL_SLAVEPORT value. Only one can be set, valid values are: ${_QMAIL_VALID_SLAVEPORTS}
.    endif
.  endif

.  if defined(QMAIL_SLAVEPORT)
_QMAIL_DEPENDS=	${QMAIL_PREFIX}/bin/qmail-send:${PORTSDIR}/mail/qmail-${QMAIL_SLAVEPORT:L}
.  else
_QMAIL_DEPENDS=	${QMAIL_PREFIX}/bin/qmail-send:${PORTSDIR}/mail/qmail
.  endif

.endif

.endif
