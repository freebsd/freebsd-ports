# New ports collection makefile for:    objc compiler
# Date created:         16 May 1998
# Whom:                 chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	objc
PORTVERSION=	3.1.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	devel/lang/objc chuckr
DISTFILES=	objc-3.1.5-bootstrap.tar.gz objc-3.1.5.tar.gz

MAINTAINER=	chuckr@freebsd.org

BUILD_DEPENDS=	$(PREFIX)/lib/libgc.a:$(PORTSDIR)/devel/boehm-gc

HAS_CONFIGURE=	yes
MAN1=		cvtimport.1 objc.1 postlink.1 vici.1
MAN3=		Array.3 AsciiFiler.3 Bag.3 Block.3 CAObject.3 Cltn.3 \
		Complex.3 Dictionary.3 Float.3 Fraction.3 IdArray.3 IntArray.3\
		BigInt.3 IntegerModp.3 Matrix.3 Message.3 Monomial.3 Object.3\
		OrdCltn.3 Paragraph.3 Point.3 Polynomial.3 Rectangle.3 \
		RunArray.3 Set.3 Sequence.3 SortCltn.3 Stack.3 String.3 \
		Symbol.3 Term.3 Text.3 TextAttribute.3 TextStyle.3 Vector.3

ALL_TARGET=	compiler
MAKE_ENV=	PATH=$(WRKDIR)/bin:$(PATH)
CONFIGURE_ENV=	PATH=$(WRKDIR)/bin:$(PATH)
CONFIGURE_ARGS=	--prefix=$(PREFIX)
#CONFIGURE_ARGS=	--prefix=$(PREFIX) --gcprefix=$(PREFIX)

.include <bsd.port.pre.mk>

pre-configure:
	(cd $(WRKDIR)/$(DISTNAME)-bootstrap;./configure --prefix=$(WRKDIR);${MAKE};${MAKE} install)

post-build:
	$(ECHO) "Building additional libraries (boehm-gc compatibility)"
	(cd $(WRKSRC); ${SETENV} PATH=$(WRKDIR)/bin:$(PATH) ./makeLibs)

pre-install:
	$(MKDIR) $(PREFIX)/share/doc/objc
	$(MKDIR) $(PREFIX)/share/doc/objc/examples
	$(MKDIR) $(PREFIX)/share/doc/objc/html
	${TAR} -cf - -C $(WRKSRC)/examples . | ${TAR} xpf - -C $(PREFIX)/share/doc/objc/examples
	${TAR} -cf - -C $(WRKSRC)/html . | ${TAR} xpf - -C $(PREFIX)/share/doc/objc/html

.include <bsd.port.post.mk>
