PORTNAME=	eb
DISTVERSION=	4.4.3
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/
DISTFILES=	${EBFILES} \
		${APPENDIXFILES:S,^,appendix/,:S,$,.tar.gz,}
DIST_SUBDIR=	eb
EXTRACT_ONLY=	${EBFILES}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	C library for accessing EB, EBG, EBXA, and EPWING CD-ROM dictionaries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf iconv libtool perl5 tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgdocdir=${DOCSDIR}
CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ON=	--with-gettext-includes=${LOCALBASE}/include \
			--with-gettext-libraries=${LOCALBASE}/lib
NLS_CONFIGURE_OFF=	--disable-nls
NLS_CONFIGURE_ENABLE=	nls

EBDOCS=		eb ebappendix ebfont ebinfo ebrefile ebstopcode ebzip
EBFILES=	${DISTNAME}${EXTRACT_SUFX}
APPENDIXFILES=	cencro-1.0 chujiten-2.3 chujiten2-2.0 chujiten6-2.3 \
		colloc-2.0 crownfj-2.0 crownfj2-1.0 crowngj-1.0 daihyakka-1.0 \
		daijirin-2.0 dd75-2.0 gendai2000-1.0 genius-1.0 genius2-1.1 \
		global-2.0 heritage-2.2 hyogen-1.0 izumi-2.0 jitenban-2.4 \
		jitenban97-2.1 kanjigen-2.0 kanjigen2-2.0 kojien-2.3 \
		kojien2-2.0 kojien4-2.2 oxford-2.0 plus-2.0 readers-2.2 \
		readers2-2.0 ruigigo-1.0 superdic98-1.0

post-extract:
	@${MKDIR} ${WRKDIR}/appendix
.for file in ${APPENDIXFILES}
	${TAR} --exclude CVS -C ${WRKDIR}/appendix -zxmf \
		${DISTDIR}/${DIST_SUBDIR}/appendix/${file}.tar.gz
.endfor

post-install:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} appendix ${STAGEDIR}${DATADIR})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libeb.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${EBDOCS:S,$,.html,} \
		${EBDOCS:S,$,-[01][0-9].html,} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
