# Created by: Motoyuki Kasahara <m-kasahr@sra.co.jp>
# $FreeBSD$

PORTNAME=	eb
PORTVERSION=	4.4.3
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/ \
		ftp://ftp.sra.co.jp/pub/misc/eb/old/eb-${PORTVERSION:C/^([0-9]+)\.([0-9]+).*/\1.\2/}/
DISTFILES=	${EBFILES} \
		${APPENDIXFILES}
EXTRACT_ONLY=	${EBFILES}

MAINTAINER=	yasu@utahime.org
COMMENT=	C library for accessing EB, EBG, EBXA, and EPWING CD-ROM dictionaries

LICENSE=	BSD3CLAUSE

EBFILES=	${DISTNAME}${EXTRACT_SUFX}
APPENDIXFILES=	appendix/cencro-1.0.tar.gz \
		appendix/chujiten-2.3.tar.gz \
		appendix/chujiten2-2.0.tar.gz \
		appendix/chujiten6-2.3.tar.gz \
		appendix/colloc-2.0.tar.gz \
		appendix/crownfj-2.0.tar.gz \
		appendix/crownfj2-1.0.tar.gz \
		appendix/crowngj-1.0.tar.gz \
		appendix/daihyakka-1.0.tar.gz \
		appendix/daijirin-2.0.tar.gz \
		appendix/dd75-2.0.tar.gz \
		appendix/gendai2000-1.0.tar.gz \
		appendix/genius-1.0.tar.gz \
		appendix/genius2-1.1.tar.gz \
		appendix/global-2.0.tar.gz \
		appendix/heritage-2.2.tar.gz \
		appendix/hyogen-1.0.tar.gz \
		appendix/izumi-2.0.tar.gz \
		appendix/jitenban-2.4.tar.gz \
		appendix/jitenban97-2.1.tar.gz \
		appendix/kanjigen-2.0.tar.gz \
		appendix/kanjigen2-2.0.tar.gz \
		appendix/kojien-2.3.tar.gz \
		appendix/kojien2-2.0.tar.gz \
		appendix/kojien4-2.2.tar.gz \
		appendix/oxford-2.0.tar.gz \
		appendix/plus-2.0.tar.gz \
		appendix/readers-2.2.tar.gz \
		appendix/readers2-2.0.tar.gz \
		appendix/ruigigo-1.0.tar.gz \
		appendix/superdic98-1.0.tar.gz

DIST_SUBDIR=	eb

PORTDOCS=	eb-01.html eb-02.html eb-03.html eb-04.html eb-05.html eb-06.html \
		eb-07.html eb-08.html eb-09.html eb-10.html eb-11.html eb-12.html \
		eb-13.html eb-14.html eb.html ebappendix-01.html ebappendix-02.html \
		ebappendix-03.html ebappendix-04.html ebappendix.html ebfont-01.html \
		ebfont-02.html ebfont-03.html ebfont-04.html ebfont.html \
		ebinfo-01.html ebinfo-02.html ebinfo-03.html ebinfo-04.html \
		ebinfo-05.html ebinfo.html ebrefile-01.html ebrefile-02.html \
		ebrefile-03.html ebrefile.html ebstopcode-01.html ebstopcode-02.html \
		ebstopcode-03.html ebstopcode.html ebzip-01.html ebzip-02.html \
		ebzip-03.html ebzip-04.html ebzip-05.html ebzip-06.html ebzip-07.html \
		ebzip-08.html ebzip-09.html ebzip-10.html ebzip.html

USE_AUTOTOOLS=	libtool
USES=		perl5 tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pkgdocdir=${DOCSDIR}
CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

APPENDIXDIR=	${DATADIR}/appendix

NLS_USES=		gettext iconv
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON= \
		--with-gettext-includes=${LOCALBASE}/include \
		--with-gettext-libraries=${LOCALBASE}/lib \
		--with-iconv-includes=${ICONV_PREFIX}/include \
		--with-iconv-libraries=${ICONV_PREFIX}/lib

post-extract:
	${RM} -fr ${WRKSRC}/zlib
	${MKDIR} ${WRKDIR}/appendix
.for file in ${APPENDIXFILES}
	${TAR} --exclude CVS -C ${WRKDIR}/appendix -zxmf \
	${DISTDIR}/${DIST_SUBDIR}/${file}
.endfor

post-install:
	(cd ${WRKDIR}/appendix && ${COPYTREE_SHARE} . ${STAGEDIR}${APPENDIXDIR} )
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libeb.so

.include <bsd.port.mk>
