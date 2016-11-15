# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vegastrike
PORTVERSION=	0.5.1.r1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}/ \
		http://ports.toco-domains.de/ \
		http://dist.codelabs.ru/fbsd/ports/vegastrike/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vega Strike data files

USES=		shebangfix tar:bzip2
SHEBANG_FILES=	modules/webpageize.py cgi-accountserver/vsconfig.py \
		cgi-accountserver/register_submit.py cgi-accountserver/register.py \
		programs/planet/process_includes.py
NO_BUILD=	yes
NO_ARCH=	yes

PORTDATA=	* .vegastrike
PLIST_DIRS=	%%DATADIR%%/movies

post-extract:
	@${FIND} ${WRKSRC} -name Makefile.am -delete

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
