# New ports collection makefile for:    objc compiler
# Version required:     1.6.8
# Date created:         16 October 1997
# Whom:                 chuckr@freebsd.org
#
# $Id: Makefile,v 1.4 1997/03/25 10:33:59 obrien Exp $
#


DISTNAME=       objc1.6.8
PKGNAME=	objc-1.6.8
CATEGORIES=     lang
MASTER_SITES=   http://www.can.nl/~stes/Software/
DISTFILES=	objc1.6.8.tar.gz objc1.6.8-i386-unknown-freebsd-static.tar.gz

MAINTAINER=     chuckr@freebsd.org

HAS_CONFIGURE=	yes
MAN1=		objc.1 objc1.1 objcpls1.1 postlink.1
MAN3=		AsciiFiler.3 Block.3 CAObject.3 Collection.3 \
		Complex.3 Dictionary.3 Float.3 Fraction.3 Integer.3 \
		IntegerModp.3 Matrix.3 Monomial.3 Object.3 Polynomial.3 \
		Sequence.3 Set.3 String.3 Symbol.3 Term.3 Tree.3 Vector.3

post-extract:
	$(CP) -R $(WRKDIR)/objc1.6.8-i386-unknown-freebsd-static/bin $(WRKSRC)

ALL_TARGET=	default
MAKE_ENV=	env "OBJCDIR=${WRKSRC}" OBJCC=$(WRKSRC)/bin/objc CFLAGS=-O
CONFIGURE_ENV=	OBJCC="env OBJCDIR=$(WRKSRC) $(WRKSRC)/bin/objc -q -g -noI -noLibs" CFLAGS=-O

.include <bsd.port.mk>
