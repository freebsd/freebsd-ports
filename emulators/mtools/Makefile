# New ports collection makefile for:    mtools
# Version required:     3.0
# Date created:         5 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.7 1996/05/27 14:09:17 jmz Exp $
#

DISTNAME=	mtools-3.0
CATEGORIES+=	emulators
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=	jmz@FreeBSD.org

HAS_CONFIGURE=  yes
CONFIGURE_ARGS+=--enable-xdf --prefix=${PREFIX}

post-patch:
	@cd ${WRKSRC}; for f in config.c mtools.5 mtools.texi; do \
	 mv $$f $$f.orig; \
	 sed -e s:/etc/mtools.conf:${PREFIX}/etc/mtools.conf: \
	 < $$f.orig > $$f; done

post-install:
	@install -c ${WRKSRC}/mtools.conf ${PREFIX}/etc
.if !defined(NOMANCOMPRESS)
	@for f in mattrib.1 mbadblocks.1 mcd.1 mcopy.1 mdel.1 mdeltree.1 \
	 mdir.1 mformat.1 mkmanifest.1 mlabel.1 mmd.1 mmount.1 mmove.1 mrd.1 \
	 mread.1 mren.1 mtest.1 mtools.1 mtype.1 mwrite.1; do \
	 gzip -fn ${PREFIX}/man/man1/$$f; done
	@gzip -fn ${PREFIX}/man/man5/mtools.5
.endif

.include <bsd.port.mk>
