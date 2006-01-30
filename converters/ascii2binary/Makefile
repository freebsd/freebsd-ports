# New ports collection makefile for:	ascii2binary
# Date created:		Sun 29 January 2006
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ascii2binary
PORTVERSION=	2.8.1
CATEGORIES=	converters
MASTER_SITES=	http://billposer.org/Software/Downloads/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert between textual representations of numbers and binary

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"		\
		LIBS="-lintl"
MAKE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"		\
		LIBS="-lintl"
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

PLIST_FILES=	bin/ascii2binary bin/binary2ascii		\
		%%NLS%%share/locale/fr/LC_MESSAGES/ascii2binary.mo

MAN1=		ascii2binary.1 binary2ascii.1

.if defined(WITHOUT_NLS)
PLIST_SUB=	NLS="@comment "
.else
PLIST_SUB=	NLS=""
.endif

pre-configure:
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's|cp -r locale|#cp -r locale|' ${WRKSRC}/Makefile
.endif

post-install:
	@${FIND} ${PREFIX}/share/locale -name ascii2binary.po -delete

.include <bsd.port.mk>
