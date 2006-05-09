# New ports collection makefile for:    objc compiler
# Date created:         16 May 1998
# Whom:                 chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	objc
PORTVERSION=	3.2.6
CATEGORIES=	lang
MASTER_SITES=	http://users.pandora.be/stes/
DISTFILES=	objc-bootstrap-${BOOTVERSION}.tar.gz objc-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable Object Compiler

HAS_CONFIGURE=	yes
BOOTVERSION=	3.1.33

ALL_TARGET=	default
MAKE_ENV=	PATH=$(WRKDIR)/bin:$(PATH)
CONFIGURE_ENV=	PATH=$(WRKDIR)/bin:$(PATH)
CONFIGURE_ARGS=	--prefix=$(PREFIX)

.include <bsd.port.pre.mk>

# byacc broken, http://www.freebsd.org/cgi/query-pr.cgi?pr=bin/85115"
.if ${OSVERSION} >= 500113
BUILD_DEPENDS+=	byaccj:${PORTSDIR}/devel/byaccj
.endif

pre-configure:
.if ${OSVERSION} >= 500113
	${REINPLACE_CMD} -e 's|byacc|byaccj|' ${WRKSRC}/configure
.endif
	cd $(WRKDIR)/${PORTNAME}-bootstrap-$(BOOTVERSION);\
	${CONFIGURE_ENV} ./configure --prefix=$(WRKDIR);${MAKE};${MAKE} install

pre-install:
	$(MKDIR) $(PREFIX)/share/doc/objc
	$(MKDIR) $(PREFIX)/share/doc/objc/examples
	$(MKDIR) $(PREFIX)/share/doc/objc/html
	${TAR} -cf - -C $(WRKSRC)/examples . | ${TAR} xpf - -C $(PREFIX)/share/doc/objc/examples
	${TAR} -cf - -C $(WRKSRC)/html . | ${TAR} xpf - -C $(PREFIX)/share/doc/objc/html

.include "${FILESDIR}/manpages.mk"

.include <bsd.port.post.mk>
