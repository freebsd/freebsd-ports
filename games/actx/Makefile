# New ports collection makefile for:   actx
# Date created:        19 Feb 1999
# Whom:                Shinya Esu <esu@yk.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	actx
PORTVERSION=	1.23
CATEGORIES=	games
MASTER_SITES=	http://rosegray.sakura.ne.jp/ActX/

MAINTAINER=	esu@yk.rim.or.jp
COMMENT=	Window sitter for X11

NO_CDROM=	'contains commercial character data'

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		actx.1
MANLANG=	"" ja

ACTXDIR=	${PREFIX}/share/examples/actx

post-extract:
	@ ${CP} ${WRKSRC}/samples/Imakefile ${WRKSRC}

post-patch:
.for i in samples/sample.actxrc
	@ ${MV} ${WRKSRC}/$i ${WRKSRC}/$i.old
	@ ${SED} -e "s#%%ACTXDIR%%#${ACTXDIR}#" ${WRKSRC}/$i.old > ${WRKSRC}/$i
.endfor

pre-configure:
	@ ${CP} ${WRKSRC}/samples/sample.actxrc ${WRKSRC}/install.actxrc
	@ ${CP} ${WRKSRC}/samples/sample.actxrc ${WRKSRC}/install.actxrc-one

post-install:
# strip binary
	@${STRIP_CMD} ${PREFIX}/bin/actx
# install japanese manual
	@${INSTALL_MAN} ${WRKSRC}/actx.jman ${PREFIX}/man/ja/man1/actx.1
	@${GZIP_CMD} ${PREFIX}/man/ja/man1/actx.1
.for i in sample.Xdefaults sample.actxrc
	@ ${INSTALL_DATA} ${WRKSRC}/samples/$i ${ACTXDIR}
.endfor
.if !defined(NOPORTDOCS)
.for i in doc/ForDevelloper.jis doc/ManualInstall.jis README.jis
	@ ${MKDIR} ${PREFIX}/share/doc/ja/actx
	@ ${INSTALL_MAN} ${WRKSRC}/$i ${PREFIX}/share/doc/ja/actx
.endfor
.endif
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
