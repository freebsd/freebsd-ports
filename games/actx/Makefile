# New ports collection makefile for:   actx
# Version required:    0.99.2
# Date created:        19 Feb 1999
# Whom:                Shinya Esu <esu@yk.rim.or.jp>
#
# $FreeBSD$
#

DISTNAME=	actx-0.99.2
PKGNAME=	actx-0.99.2
CATEGORIES=	games
MASTER_SITES=	http://www.astr.tohoku.ac.jp/~taji/ActX/

MAINTAINER=	esu@yk.rim.or.jp

LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=yes
NO_CDROM=	'contains commercial character data'
ACTXDIR=	${PREFIX}/share/examples/actx

post-extract:
	@ ${CP} ${WRKSRC}/samples/Imakefile ${WRKSRC}
	@ ${CP} ${WRKSRC}/samples/sample.actxrc ${WRKSRC}/install.actxrc

post-patch:
.for i in install.actxrc samples/sample.actxrc
	@ ${MV} ${WRKSRC}/$i ${WRKSRC}/$i.old
	@ ${SED} -e "s#%%ACTXDIR%%#${ACTXDIR}#" ${WRKSRC}/$i.old > ${WRKSRC}/$i
.endfor

post-install:
.for i in sample.Xdefaults sample.actxrc
	@ ${INSTALL_DATA} ${WRKSRC}/samples/$i ${ACTXDIR}
.endfor
.if !defined(NOPORTDOCS)
.for i in doc/ForDevelloper.jis README.jis
	@ ${MKDIR} ${PREFIX}/share/doc/ja/actx
	@ ${INSTALL_MAN} ${WRKSRC}/$i ${PREFIX}/share/doc/ja/actx
.endfor
.endif
	@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
