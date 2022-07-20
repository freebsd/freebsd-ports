PORTNAME=		cvslines
PORTVERSION=		1.6.9
CATEGORIES=		devel
MASTER_SITES=		SF

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Wrapper to ease merging of changes between CVS branches

WRKSRC=			${WRKDIR}/${PORTNAME}
NO_BUILD=		yes
USES=			shebangfix perl5
SHEBANG_FILES=		cvslines
.for ii in s s_check s-check s-commit s-config s-status
PLIST_FILES+=	bin/cvsline${ii}
.endfor
PLIST_FILES+=	man/man1/cvslines.1.gz

pre-patch:
	@${REINPLACE_CMD} -i '' -e 's|the the|the|' ${WRKSRC}/cvslines.1

do-install:
	PREFIX=${STAGEDIR}${PREFIX} ${PERL5} ${WRKSRC}/INSTALL ${WRKSRC}/CONFIG

.include <bsd.port.mk>
