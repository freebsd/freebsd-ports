# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evilfinder
PORTVERSION=	1.00
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://lcamtuf.coredump.cx/:src \
	http://lcamtuf.coredump.cx/evilfinder/:numbers
DISTFILES=	ef.tgz:src \
	evilnumbers.dat:numbers
EXTRACT_ONLY=	ef.tgz

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Numerologically determine the evilness of things

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_SUB=	yes

PLIST_FILES=	bin/ef \
		%%WRAPPER%%bin/evilfinder \
		libexec/ef-shuffle

PORTDATA=	evilnumbers.dat
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS WRAPPER
WRAPPER_DESC=	Evilfinder local wrapper
OPTIONS_DEFAULT=	WRAPPER

WRAPPER_RUN_DEPENDS=	lynx:www/lynx

post-extract:
	@${CP} ${DISTDIR}/evilnumbers.dat ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|evilnumbers.dat|${DATADIR}/evilnumbers.dat|' \
		-e 's|.tmp-%d-%u|/tmp/.tmp-%d-%u|' \
		-e 's|./shuffle|${PREFIX}/libexec/ef-shuffle|' \
		-e 's|inline||' \
		${WRKSRC}/ef.c
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|/dev/stdin|-stdin|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${FILESDIR}/evilfinder > ${WRKSRC}/evilfinder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ef ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shuffle ${STAGEDIR}${PREFIX}/libexec/ef-shuffle
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/evilnumbers.dat ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/evilfinder ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
