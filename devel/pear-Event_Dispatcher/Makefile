# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Event_Dispatcher
PORTVERSION=	1.1.0
CATEGORIES=	devel pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR dispatch notifications using PHP callbacks

USES=	pear

post-extract:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
