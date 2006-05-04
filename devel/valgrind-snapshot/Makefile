# Ports collection makefile for:	valgrind
# Date created:				April 19 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	valgrind
PORTVERSION=	352
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://www.rabson.org/
PKGNAMESUFFIX=	-snapshot
DISTNAME=	${PORTNAME}-current-${PORTVERSION}

MAINTAINER=	barner@FreeBSD.org
COMMENT=	A (memory) debugging and profiling tool

CONFLICTS=	valgrind-[0-9]*
LATEST_LINK=	valgrind-snapshot

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS+=	autoconf:259 aclocal:19 automake:19
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
PLIST_SUB+=	RELENG_4="@comment "
PLIST_SUB+=	RELENG_5="@comment "
PLIST_SUB+=	RELENG_6="@comment "
PLIST_SUB+=	RELENG_7=""
.else
.if ${OSVERSION} >= 600000
PLIST_SUB+=	RELENG_4="@comment "
PLIST_SUB+=	RELENG_5="@comment "
PLIST_SUB+=	RELENG_6=""
PLIST_SUB+=	RELENG_7="@comment "
.else
.if ${OSVERSION} >= 500000
PLIST_SUB+=	RELENG_4="@comment "
PLIST_SUB+=	RELENG_5=""
PLIST_SUB+=	RELENG_6="@comment "
PLIST_SUB+=	RELENG_7="@comment "
.else
PLIST_SUB+=	RELENG_4=""
PLIST_SUB+=	RELENG_5="@comment "
PLIST_SUB+=	RELENG_6="@comment "
PLIST_SUB+=	RELENG_7="@comment "
.endif
.endif
.endif

.if ${PERL_LEVEL} < 500601
IGNORE=		can\'t be built. Your Perl version is too old. Please use lang/perl5.8 port to upgrade your Perl
.endif

PROCFS!=	/sbin/mount | ${GREP} '^procfs' | ${AWK} '{print $1}'

pre-everything::

.if ${PROCFS}
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Check if procfs is running: YES"
.else
#
# /proc is not mounted on the machine in the package building cluster that
# that builds the list of IGNOREd ports (but it is on the build machines),
# so we need to make an exception here.
#
.ifndef (PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=	needs a running procfs, which is not\n\
\ \ \ \ \ activated on your system. Please read the procfs\(5\)\n\
\ \ \ \ \ man page and add the following line to /etc/fstab:\n\
\n\
\ \ \ \ \ proc /proc procfs rw 0 0\n\
\n
.endif
.endif

pre-patch:
.ifdef(NOPORTDOCS)
	${FIND} ${WRKSRC} -name "Makefile.in" -exec \
		${REINPLACE_CMD} -e "s/docs//g" {} \;
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/coregrind/vg_unistd.h \
		${PREFIX}/include/valgrind

# Check if kernel is built with USER_LDT option (FreeBSD 4 only)
.if ${OSVERSION} < 500000
	@${PREFIX}/bin/valgrind --tool=memcheck true 2> ${WRKDIR}/ldt.test
	@${GREP} i386_set_ldt ${WRKDIR}/ldt.test >/dev/null &&\
	${ECHO_CMD} !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! && \
	${ECHO_CMD} Please rebuild your kernel with ``options USER_LDT''! && \
	${ECHO_CMD} Otherwise, valgrind will not be able to perform pointer analysis! && \
	${ECHO_CMD} !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! || true
.endif

# Generate suppression files
.ifndef (PACKAGE_BUILDING)
	@yes | ${PREFIX}/bin/valgrind --tool=memcheck --gen-suppressions=yes true 2>&1 \
		| ${SED} -e 's,.*{$$,{,'  \
		| ${GREP} -v '^=' \
		> ${WRKDIR}/freebsd-default.supp || \
		${RM} ${WRKDIR}/freebsd-default.supp
.endif

.if exists(${WRKDIR}/freebsd-default.supp)
	@${INSTALL_DATA} ${WRKDIR}/freebsd-default.supp \
		${PREFIX}/lib/valgrind
PLIST_SUB+=	VALGRIND_SUPPFILE=""
	@${ECHO} ""
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'
	@${ECHO} ""
.else
PLIST_SUB+=	VALGRIND_SUPPFILE="@comment "
.endif

.include <bsd.port.post.mk>
