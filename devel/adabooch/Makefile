# Created by: David Holm <david@realityrift.com>
# $FreeBSD$

PORTNAME=	adabooch
PORTVERSION=	20030309
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE}
DISTNAME=	bc-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Library which provide container classes as well as powertools for Ada

LICENSE=	GPLv2

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/adabooch
	for i in `${SED} -n "/lib\/adabooch\// s/lib\/adabooch\///p" pkg-plist`; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${STAGEDIR}${PREFIX}/lib/adabooch; \
	done
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/adabooch/demo
	for i in `${SED} -n "/share\/adabooch\/demo\// s/share\/adabooch\/demo\///p" pkg-plist`; do \
		${INSTALL_DATA} ${WRKSRC}/demo/$${i} ${STAGEDIR}${PREFIX}/share/adabooch/demo; \
	done
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/adabooch/test
	for i in `${SED} -n "/share\/adabooch\/test\// s/share\/adabooch\/test\///p" pkg-plist`; do \
		${INSTALL_DATA} ${WRKSRC}/test/$${i} ${STAGEDIR}${PREFIX}/share/adabooch/test; \
	done

post-install:
	@${ECHO}
	@${ECHO} "The booch library has been installed into ${PREFIX}/lib/adabooch"
	@${ECHO}

.include <bsd.port.mk>
