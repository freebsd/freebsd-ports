# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	libtool
PORTVERSION=	1.3.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool
DISTNAME=	libtool-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT=	Generic shared library support script

LATEST_LINK=	libtool13
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ltdl-install \
		--program-suffix=13
CONFIGURE_ENV=	PREFIX=${PREFIX} PACKAGE=libtool13
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
	@${MV} -f ${WRKSRC}/libtool.m4 ${WRKSRC}/libtool13.m4
	@${REINPLACE_CMD} -e 's|libtool.m4|libtool13.m4|g' \
			  ${WRKSRC}/Makefile.in
	@${MV} -f ${WRKSRC}/doc/libtool.info ${WRKSRC}/doc/libtool13.info
	@${MV} -f ${WRKSRC}/doc/libtool.texi ${WRKSRC}/doc/libtool13.texi

post-install:
	@-${RM} -fr ${PREFIX}/libexec/libtool13
	${MKDIR} ${PREFIX}/libexec/libtool13
.for i in libtool libtoolize
	${LN} -sf ${PREFIX}/bin/${i}13 ${PREFIX}/libexec/libtool13/${i}
.endfor
.for i in config.guess config.sub
	${MV} ${PREFIX}/share/libtool13/${i}13 ${PREFIX}/share/libtool13/${i}
.endfor
	${LN} -sf ${PREFIX}/share/libtool13/ltconfig13 \
		${PREFIX}/share/libtool13/ltconfig

.include <bsd.port.mk>
