# New ports collection makefile for:    mtools + support 1232KB , Unicode LFN
# Date created:		6 October 1997
# Whom:			WATANABE junya <junya-w@remus.dti.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mtools
PORTVERSION=	3.9.6
PORTREVISION=	1
CATEGORIES=	japanese emulators
MASTER_SITES=	ftp://ftp.tux.org/pub/knaff/mtools/  \
		http://mtools.linux.lu/  \
		${MASTER_SITE_LOCAL} \
		${MASTER_SITE_PORTS_JP}
MASTER_SITE_SUBDIR=	steve
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}.PC98.patch.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for manipulating MSDOS files + support 1232KB , Unicode LFN

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-xdf

USE_GMAKE=	yes

MAN1=		mattrib.1 mbadblocks.1 mcat.1 mcd.1 mcopy.1 mdel.1 mdeltree.1 \
		mdir.1 mdu.1 mformat.1 mkmanifest.1 mlabel.1 mmd.1 mmount.1 \
		mmove.1 mpartition.1 mrd.1 mread.1 mren.1 mshowfat.1 \
		mtoolstest.1 mtools.1 mtype.1 mzip.1
MAN5=		mtools.5
MLINKS=		mcopy.1 mwrite.1

post-patch:
	@cd ${WRKSRC}; \
	  ${GZCAT} ${DISTDIR}/mtools-3.9.6.PC98.patch.gz | ${PATCH} -d . >/dev/null 2>&1; \
	  for f in config.c mtools.5 mtools.texi; do \
	    ${MV} $$f $$f.orig; \
	    ${SED} -e s:/etc/mtools.conf:${PREFIX}/etc/mtools.conf: \
	    < $$f.orig > $$f; done
	@cd ${WRKSRC}/scripts; for f in ocopy xcopy; do \
	 if [ ! -f $$f -a -f $$f.orig ]; then ${CP} -p $$f.orig $$f ; fi \
	 done

post-install:
	@#	mwrite has been removed by author, but we'll keep it just a bit longer
	@${LN} -sf ${PREFIX}/bin/mtools ${PREFIX}/bin/mwrite
	@${INSTALL_DATA} ${WRKSRC}/mtools.conf ${PREFIX}/etc
	@${ECHO} "Please verify ${PREFIX}/etc/mtools.conf for your machine."
	@install-info ${PREFIX}/info/mtools.info ${PREFIX}/info/dir

.include <bsd.port.mk>
