# New ports collection makefile for:    mtools
# Version required:     3.5a
# Date created:         5 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.13 1997/04/03 02:38:43 jmz Exp $
#

DISTNAME=	mtools-3.5a
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jmz@FreeBSD.org

HAS_CONFIGURE=  yes
CONFIGURE_ARGS+=--enable-xdf --prefix=${PREFIX}

USE_GMAKE=	yes

MAN1=		mattrib.1 mbadblocks.1 mcd.1 mcopy.1 mdel.1 mdeltree.1 \
		mdir.1 mformat.1 mkmanifest.1 mlabel.1 mmd.1 mmount.1 mmove.1 \
		mrd.1 mread.1 mren.1 mtoolstest.1 mtools.1 mtype.1 mwrite.1
MAN5=		mtools.5

post-patch:
	@cd ${WRKSRC}; for f in config.c mtools.5 mtools.texi; do \
	 mv $$f $$f.orig; \
	 sed -e s:/etc/mtools.conf:${PREFIX}/etc/mtools.conf: \
	 < $$f.orig > $$f; done

post-install:
	@install -c ${WRKSRC}/mtools.conf ${PREFIX}/etc

.include <bsd.port.mk>
