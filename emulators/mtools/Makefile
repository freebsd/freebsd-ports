# New ports collection makefile for:    mtools
# Version required:     3.9.6
# Date created:         5 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	mtools-3.9.6
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.tux.org/pub/knaff/mtools/  \
		http://mtools.linux.lu/

MAINTAINER=	jmz@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-xdf

USE_GMAKE=	yes

MAN1=		mattrib.1 mbadblocks.1 mcat.1 mcd.1 mcopy.1 mdel.1 mdeltree.1 \
		mdir.1 mdu.1 mformat.1 mkmanifest.1 mlabel.1 mmd.1 mmount.1 \
		mmove.1 mpartition.1 mrd.1 mread.1 mren.1 mshowfat.1 \
		mtoolstest.1 mtools.1 mtype.1 mzip.1
MAN5=		mtools.5

post-patch:
	@cd ${WRKSRC}; for f in config.c mtools.5 mtools.texi; do \
	 ${MV} $$f $$f.orig; \
	 ${SED} -e s:/etc/mtools.conf:${PREFIX}/etc/mtools.conf: \
	 < $$f.orig > $$f; done
	@cd ${WRKSRC}/scripts; for f in ocopy xcopy; do \
	 if [ ! -f $$f -a -f $$f.orig ]; then ${CP} -p $$f.orig $$f ; fi \
	 done

post-install:
	@#	mwrite has been removed by author, but we'll keep it just a bit longer
	@${LN} -sf ${PREFIX}/bin/mtools ${PREFIX}/bin/mwrite
	@${LN} -sf ${PREFIX}/man/man1/mcopy.1.gz ${PREFIX}/man/man1/mwrite.1.gz
	@${INSTALL_DATA} ${WRKSRC}/mtools.conf ${PREFIX}/etc
	@${ECHO} "Please verify ${PREFIX}/etc/mtools.conf for your machine."
	@install-info ${PREFIX}/info/mtools.info ${PREFIX}/info/dir

.include <bsd.port.mk>
