# New ports collection makefile for:	zh-vim-scdoc
# Date created:				Feb 3 2004
# Whom:					hamigua <hamigua@hotpop.com>
#
# $FreeBSD$
#

PORTNAME=	vim-scdoc
PORTVERSION=	0.7.0
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-s//}
DISTNAME=	${PORTNAME:S/-s//}-${PORTVERSION}

MAINTAINER=	hamigua@hotpop.com
COMMENT=	Vim documentation Simplified Chinese

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

PLIST_SUB=	PATH_SUB=vim63
NO_BUILD=	yes
VIM_PATH=	${PREFIX}/share/vim/vim63
VIM_DOCS_PATH=	${VIM_PATH}/doc.zh_CN
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	@${MKDIR} ${WRKSRC}/doc.zh_CN
	${CP} -rf ${WRKSRC}/doc/ ${WRKSRC}/doc.zh_CN/
	(cd ${WRKSRC}; ${TAR} -cf - doc.zh_CN) | \
	${TAR} --exclude CVS -xf - -C ${VIM_PATH}/
.for i in AUTHORS INSTALL README VERSION ChangeLog LICENSE TODO dict.txt guides.txt
	${INSTALL_DATA} ${WRKSRC}/${i} ${VIM_DOCS_PATH}/
.endfor

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
