# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	fistgen
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.filesystems.org/pub/fistgen/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language for describing stackable filesystems

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	pkg-message

MAN8=		fistgen.8
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	sbin/fistgen

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
.for dir in templates
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR})
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for dir in copyfs cryptfs gzipfs uuencodefs tests
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${EXAMPLESDIR})
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
