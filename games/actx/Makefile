# New ports collection makefile for:   actx
# Date created:        19 Feb 1999
# Whom:                Shinya Esu <esu@yk.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	actx
PORTVERSION=	1.01
CATEGORIES=	games
MASTER_SITES=	http://kurumi.sakura.ne.jp/~chimari/ActX/

MAINTAINER=	esu@yk.rim.or.jp

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		actx.1
MANLANG=	"" ja
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
# strip binary
	@strip ${PREFIX}/bin/actx
# install japanese manual
	@${INSTALL_MAN} ${WRKSRC}/actx.jman ${PREFIX}/man/ja/man1/actx.1
	@${GZIP_CMD} ${PREFIX}/man/ja/man1/actx.1
.for i in sample.Xdefaults sample.actxrc
	@ ${INSTALL_DATA} ${WRKSRC}/samples/$i ${ACTXDIR}
.endfor
.if !defined(NOPORTDOCS)
.for i in doc/ForDevelloper.jis README.jis
	@ ${MKDIR} ${PREFIX}/share/doc/ja/actx
	@ ${INSTALL_MAN} ${WRKSRC}/$i ${PREFIX}/share/doc/ja/actx
.endfor
.endif
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
