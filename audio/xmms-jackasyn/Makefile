# New ports collection makefile for:	xmms-jackasyn
# Date created:		2006-03-09
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	jackasyn
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://gige.xdv.org/libjackasyn/download/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	XMMS plugin for jack using libjackasyn

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		jackasyn.0:${PORTSDIR}/audio/libjackasyn

DEPRECATED=	development has ceased; try audio/xmms-jack instead
EXPIRATION_DATE=2011-02-11

USE_GNOME=	gtk12 gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CXXFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CXXFLAGS}"

SUB_FILES=	pkg-message
PLIST_FILES=	lib/xmms/Output/libjackxmms.so

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|OSS Driver configuration|Jackasyn Driver configuration|g' ${WRKSRC}/configure.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libjackxmms.so \
		${PREFIX}/lib/xmms/Output/libjackxmms.so

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
