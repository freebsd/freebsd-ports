# Ports collection makefile for:	valgrind
# Date created:				April 15 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	valgrind
PORTVERSION=	352
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://www.rabson.org/
DISTNAME=	${PORTNAME}-stable-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A (memory) debugging and profiling tool

ONLY_FOR_ARCHS=	i386
CONFLICTS=	valgrind-snapshot-[0-9]*
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS+=	autoconf:262 aclocal:19 automake:19
CONFIGURE_ARGS+=--enable-maintainer-mode
USE_PERL5_BUILD=yes
USE_GCC=	3.4

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
IGNORE=	FreeBSD 8.x is unsupported
.elif ${OSVERSION} >= 700000
PLIST_SUB+=	RELENG_6="@comment "
PLIST_SUB+=	RELENG_7=""
.else
PLIST_SUB+=	RELENG_6=""
PLIST_SUB+=	RELENG_7="@comment "
.endif

PROCFS!=	if test -r /proc/curproc/status; then echo "procfs"; else echo ""; fi

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
\n\n
.endif
.endif

pre-patch:
.ifdef(NOPORTDOCS)
	${FIND} ${WRKSRC} -name "Makefile.am" -exec \
		${REINPLACE_CMD} -e "s/docs//g" {} \;
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/coregrind/vg_unistd.h \
		${PREFIX}/include/valgrind

.ifndef (PACKAGE_BUILDING)
	@yes | ${PREFIX}/bin/valgrind --tool=memcheck --gen-suppressions=yes true 2>&1 \
		| ${SED} -e 's,.*{$$,{,'  \
		| ${GREP} -v '^=' \
		> ${WRKDIR}/freebsd-default.supp || \
		${RM} ${WRKDIR}/freebsd-default.supp
.endif

	@${ECHO} ""
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'
	@${ECHO} ""

.if exists(${WRKDIR}/freebsd-default.supp)
	@${INSTALL_DATA} ${WRKDIR}/freebsd-default.supp \
		${PREFIX}/lib/valgrind
PLIST_SUB+=	VALGRIND_SUPPFILE=""
.else
PLIST_SUB+=	VALGRIND_SUPPFILE="@comment "
.endif

.include <bsd.port.post.mk>
