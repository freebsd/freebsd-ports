# New ports collection makefile for:	verbiste
# Date created:				16 November 2005
# Whom:					Dan Phillips <dan-ports@dp.id.au>
#
# $FreeBSD$
#

PORTNAME=	verbiste
PORTVERSION=	0.1.22
CATEGORIES=	french textproc
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	French verb conjugator/deconjugator

USE_GETTEXT=	yes
USE_GNOME+=	gnomehack ltverhack libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.if !defined(PKGNAMEPREFIX)

USE_ICONV=	yes
USE_LDCONFIG=	yes

MAN1=		french-conjugator.1 french-deconjugator.1
MAN3=		verbiste.3
MANLANG=	"" fr

post-install:
	${MKDIR} ${EXAMPLESDIR}
.for f in README *.java *.c
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${EXAMPLESDIR}

.endif

.include <bsd.port.mk>
