# New ports collection makefile for:    objc compiler
# Version required:     1.8.18
# Date created:         16 May 1998
# Whom:                 chuckr@freebsd.org
#
# $Id: Makefile,v 1.6 1998/05/15 02:48:21 chuckr Exp $
#

DISTNAME=       objc-1.8.18
CATEGORIES=     lang
MASTER_SITES=   http://www.can.nl/~stes/Software/
DISTFILES=	objc-1.8.18.tar.gz bootstrap-1.8.17.tar.gz

MAINTAINER=     chuckr@freebsd.org

HAS_CONFIGURE=	yes
MAN1=		cvtimport.1 objc.1 postlink.1
MAN3=		AsciiFiler.3 Array.3 CAObject.3 Bag.3 Block.3 Complex.3 \
		Cltn.3 Dictionary.3 Float.3 Fraction.3 IdArray.3 IntArray.3 \
		Integer.3 IntegerModp.3 Matrix.3 Monomial.3 Object.3 \
		OrdCltn.3 Point.3 Polynomial.3 Rectangle.3 Sequence.3 Set.3 \
		SortCltn.3 Stack.3 String.3 Symbol.3 Term.3 Vector.3

BUILD_DEPENDS=	$(PREFIX)/lib/libgc.a:$(PORTSDIR)/devel/boehm-gc

ALL_TARGET=	default cakit objcplus bootstrap
MAKE_ENV=	PATH=$(WRKDIR)/bootstrap/bin:$(PATH)
CONFIGURE_ENV=	PATH=$(WRKDIR)/bootstrap/bin:$(PATH)
CONFIGURE_ARGS=	--prefix=$(PREFIX) --gcprefix=$(PREFIX)

pre-configure:
	(cd $(WRKDIR)/bootstrap;./configure --prefix=$(WRKDIR)/bootstrap --gcprefix=$(PREFIX);$(MKDIR) $(WRKDIR)/bootstrap/bin;make default install)

post-build:
	(cd $(WRKSRC); env PATH=$(WRKDIR)/bootstrap/bin:$(PATH) OBJCDIR=$(WRKSRC) ./moreLibs -boehm)

post-install:
	$(MKDIR) $(PREFIX)/share/doc/objc
	$(INSTALL_DATA) $(WRKSRC)/manual.html $(PREFIX)/share/doc/objc

.include <bsd.port.mk>
