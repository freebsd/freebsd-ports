# New ports collection makefile for:    mtools
# Version required:     3.8
# Date created:         5 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.18 1997/12/24 01:21:25 alex Exp $
#

DISTNAME=	mtools-3.8
CATEGORIES=	emulators
MASTER_SITES=   ftp://linux.wauug.org/pub/knaff/mtools/ \
                ftp://sunsite.unc.edu/pub/Linux/utils/disk-management/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	mtools-3.8-1611.diff.gz

MAINTAINER=	jmz@FreeBSD.org

PATCH_DIST_STRIP=	-p1
HAS_CONFIGURE=  yes
CONFIGURE_ARGS= --enable-xdf --prefix=${PREFIX}

USE_GMAKE=	yes

MAN1=		mattrib.1 mbadblocks.1 mcd.1 mcopy.1 mdel.1 mdeltree.1 \
		mdir.1 mdu.1 mformat.1 mkmanifest.1 mlabel.1 mmd.1 mmount.1 mmove.1 \
		mrd.1 mread.1 mren.1 mshowfat.1 mtoolstest.1 mtools.1 mtype.1 mwrite.1 \
		mzip.1
MAN5=		mtools.5

post-patch:
	@cd ${WRKSRC}; for f in config.c mtools.5 mtools.texi; do \
	 mv $$f $$f.orig; \
	 sed -e s:/etc/mtools.conf:${PREFIX}/etc/mtools.conf: \
	 < $$f.orig > $$f; done
	@cd ${WRKSRC}/scripts; for f in ocopy xcopy; do \
	 if [ ! -f $$f -a -f $$f.orig ]; then cp -p $$f.orig $$f ; fi \
	 done

post-install:
	@install -c ${WRKSRC}/mtools.conf ${PREFIX}/etc
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/mtools.info ${PREFIX}/info/dir

.include <bsd.port.mk>
