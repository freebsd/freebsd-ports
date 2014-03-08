# Created by: Jun-ichiro itojun Itoh <itojun@itojun.org>
# $FreeBSD$

PORTNAME=	qvplay
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.asahi-net.or.jp/~xg2k-hys/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital camera downloading tool for Casio QV series

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
WRKSRC=		${WRKDIR}/QVplay095/obj/FreeBSD

CFLAGS+=	-Wno-return-type
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/qvalldel \
		bin/qvplay \
		bin/qvrec

MAN1=		qvalldel.1 qvplay.1 qvrec.1

PORTDOCS=	FAQ.txt HISTORY PROTOCOL.eng PROTOCOL.txt \
		README README.FreeBSD README.eng

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${MKDIR} ${WRKSRC}
	@${REINPLACE_CMD} \
		-e 's|/usr/local/bin|$${PREFIX}/bin|' \
		-e 's|/usr/local/man/man1|$${PREFIX}/man/man1|' \
		-e 's|$$(INSTALL_PROGRAM) -o root -g bin -m 444 $$(MAN1) $$(mandir)/$$(MAN1)|$$(INSTALL_DATA) $$(MAN1) $$(mandir)/$$(MAN1)|' \
		-e 's|$$(INSTALL_PROGRAM) -o root -g bin -m 444 $$(MAN2) $$(mandir)/$$(MAN2)|$$(INSTALL_DATA) $$(MAN2) $$(mandir)/$$(MAN2)|' \
		-e 's|$$(INSTALL_PROGRAM) -o root -g bin -m 444 $$(MAN3) $$(mandir)/$$(MAN3)|$$(INSTALL_DATA) $$(MAN3) $$(mandir)/$$(MAN3)|' \
			${WRKSRC}/../../src/Makefile.in

pre-configure:
	@(cd ${WRKDIR}/QVplay095; ./setup FreeBSD)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/../../|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
