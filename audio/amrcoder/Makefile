# Created by: Andrew Wingorodov (Wingborn) <programmer@coolsoft.ru>
# $FreeBSD$

PORTNAME=	amrcoder
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://ftp.us.sinuspl.net/pub/src/ \
		http://ftp.uni-erlangen.de/pub/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AMR encoder/decoder for Mbuni MMS Gateway (www.mbuni.org)

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

USES=		uidfix tar:tgz

post-extract:
	@${RM} ${WRKSRC}/*.o

post-patch:
	${REINPLACE_CMD} -e 's|-O4||' ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
