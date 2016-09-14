# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	privman
PORTVERSION=	0.9.3
PORTREVISION=	5
CATEGORIES=	devel security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Library that makes it easy for programs to use privilege separation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Unfetchable (google code has gone away)

USES=		autoreconf libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$$(PACKAGE).d|$$(PACKAGE)|g' \
		-e 's|$$(sysconfdir)/$$(PACKAGE)|$$(DESTDIR)$$(sysconfdir)/$$(PACKAGE)|' \
		${WRKSRC}/etc/Makefile.am
	@${REINPLACE_CMD} -e \
		'/^CFLAGS/s|-O2 -g|@CFLAGS@| ; \
		 /^CXXFLAGS/s|-O2 -g|@CXXFLAGS@| ; \
		 s|@PACKAGE@.d|@PACKAGE@| ; \
		 s|-lstdc++||' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e \
		'/^CFLAGS/s|-O2 -g|@CFLAGS@|' ${WRKSRC}/tests/Makefile.am
# microb calls sqrt which requires -lm on some architectures
	@${ECHO_CMD} 'microb_LDADD = $$(LDADD) -lm' >> ${WRKSRC}/tests/Makefile.am

.include <bsd.port.mk>
