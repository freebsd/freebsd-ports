# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME?=	libtool
PORTVERSION=	1.4.3
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool
DISTNAME=	libtool-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT?=	Generic shared library support script

LATEST_LINK?=	libtool14
GNU_CONFIGURE=	 yes
CONFIGURE_ARGS?= --disable-ltdl-install
CONFIGURE_ARGS+= --program-suffix=14
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX} PACKAGE=libtool14
USE_REINPLACE=	yes

.if defined(USE_LIBTOOL) || defined(USE_LIBTOOL_VER)
pre-everything:
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_LIBTOOL' or 'USE_LIBTOOL_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_LIBTOOL) || defined(USE_LIBTOOL_VER)

post-extract:
	@${MV} -f ${WRKSRC}/libtool.m4 ${WRKSRC}/libtool14.m4
	@${MV} -f ${WRKSRC}/ltdl.m4 ${WRKSRC}/ltdl14.m4
	@${REINPLACE_CMD} -e 's|libtool.m4|libtool14.m4|g' \
			  -e 's|ltdl.m4|ltdl14.m4|g' ${WRKSRC}/Makefile.in
	@${MV} -f ${WRKSRC}/doc/libtool.info ${WRKSRC}/doc/libtool14.info
	@${MV} -f ${WRKSRC}/doc/libtool.texi ${WRKSRC}/doc/libtool14.texi

.if ${PORTNAME} == "libtool"
post-install:
	@-${RM} -fr ${PREFIX}/libexec/libtool14
	${MKDIR} ${PREFIX}/libexec/libtool14
.for i in libtool libtoolize
	${LN} -sf ${PREFIX}/bin/${i}14 ${PREFIX}/libexec/libtool14/${i}
.endfor
.for i in config.guess config.sub
	${MV} ${PREFIX}/share/libtool14/${i}14 ${PREFIX}/share/libtool14/${i}
.endfor
.endif

.include <bsd.port.mk>
