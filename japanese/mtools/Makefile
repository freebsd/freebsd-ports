# New ports collection makefile for:    mtools + support 1232KB , Unicode LFN
# Version required:     3.6
# Date created:		6 October 1997
# Whom:			WATANABE junya <junya-w@remus.dti.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	mtools-3.6
PKGNAME=	ja-mtools-3.6
CATEGORIES=	japanese emulators
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/
DISTFILES=	mtools-3.6.tar.gz mtools-3.6.PC98.patch.gz

MAINTAINER=	junya-w@remus.dti.ne.jp

EXTRACT_ONLY=	mtools-3.6.tar.gz

GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--enable-xdf
CONFIGURE_TARGET=	# empty

USE_GMAKE=	yes

MAN1=		mattrib.1 mbadblocks.1 mcd.1 mcopy.1 mdel.1 mdeltree.1 \
		mdir.1 mformat.1 mkmanifest.1 mlabel.1 mmd.1 mmount.1 mmove.1 \
		mrd.1 mread.1 mren.1 mtoolstest.1 mtools.1 mtype.1 mwrite.1 mzip.1
MAN5=		mtools.5
ALL_TARGET=	all info

post-patch:
	@(cd ${WRKSRC} ; \
	  ${GZCAT} ${DISTDIR}/mtools-3.6.PC98.patch.gz | ${PATCH} -d . >/dev/null 2>&1; \
	  for f in config.c mtools.5 mtools.texi; do \
	    ${MV} $$f $$f.orig; \
	    ${SED} -e s:/etc/mtools.conf:${PREFIX}/etc/mtools.conf: \
	    < $$f.orig > $$f; done ;\
	)

post-install:
	@install -c ${WRKSRC}/mtools.conf ${PREFIX}/etc
	@install-info ${PREFIX}/info/mtools.info ${PREFIX}/info/dir

.include <bsd.port.mk>
