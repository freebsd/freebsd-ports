# Created by: se
# $FreeBSD$

PORTNAME=	ez-ipupdate
PORTVERSION=	3.0.11b8
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://dyn.pl/client/UNIX/ez-ipupdate/ \
		http://www.yi.org/help/software/ \
		http://www.devil-linux.us/pub/devel/sources/1.3/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Update your host name on any dynamic DNS service

USE_RC_SUBR=	ez-ipupdate
GNU_CONFIGURE=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} example-*.conf ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${WRKSRC}/example.conf \
			${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
