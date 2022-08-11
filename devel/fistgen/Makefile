PORTNAME=	fistgen
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.filesystems.org/pub/fistgen/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language for describing stackable filesystems

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	pkg-message

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	sbin/fistgen \
		man/man8/fistgen.8.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for dir in templates
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR})
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README \
		${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for dir in copyfs cryptfs gzipfs uuencodefs tests
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
