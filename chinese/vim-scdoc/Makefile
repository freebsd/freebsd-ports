# New ports collection makefile for:	zh-vim-scdoc
# Date created:				Feb 3 2004
# Whom:					hamigua <hamigua@hotpop.com>
#
# $FreeBSD$
#

PORTNAME=	vim-scdoc
PORTVERSION=	0.6.0
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-s//}
DISTNAME=	${PORTNAME:S/-s//}-${PORTVERSION}

MAINTAINER=	hamigua@hotpop.com
COMMENT=	Vim documentation Simplified Chinese

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

PLIST_SUB=	PATH_SUB=vim62
NO_BUILD=	yes
VIM_PATH=	${PREFIX}/share/vim/vim62
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	@${MKDIR} ${WRKSRC}/doc.zh_CN
	${CP} -rf ${WRKSRC}/doc/ ${WRKSRC}/doc.zh_CN/
	(cd ${WRKSRC}; ${TAR} -cf - doc.zh_CN) | \
	${TAR} --exclude CVS -xf - -C ${VIM_PATH}/

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
