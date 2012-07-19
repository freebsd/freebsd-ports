# New ports collection makefile for:	evilfinder
# Date created:				11 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

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

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/ef \
	%%WRAPPER%%bin/evilfinder \
	libexec/ef-shuffle

PORTDATA=	evilnumbers.dat
PORTDOCS=	README

OPTIONS_DEFINE=	WRAPPER
WRAPPER_DESC=	Evilfinder local wrapper
OPTIONS_DEFAULT=	WRAPPER

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWRAPPER}
RUN_DEPENDS+=	lynx:${PORTSDIR}/www/lynx
PLIST_SUB+=	WRAPPER=""
.else
PLIST_SUB+=	WRAPPER="@comment "
.endif

post-extract:
	@${CP} ${DISTDIR}/evilnumbers.dat ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|evilnumbers.dat|${DATADIR}/evilnumbers.dat|' \
		-e 's|.tmp-%d-%u|/tmp/.tmp-%d-%u|' \
		-e 's|./shuffle|${PREFIX}/libexec/ef-shuffle|' \
		-e 's|inline||' \
		${WRKSRC}/ef.c
.if ${PORT_OPTIONS:MWRAPPER}
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|/dev/stdin|-stdin|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${FILESDIR}/evilfinder > ${WRKSRC}/evilfinder
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ef ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shuffle ${PREFIX}/libexec/ef-shuffle
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/evilnumbers.dat ${DATADIR}
.if ${PORT_OPTIONS:MWRAPPER}
	${INSTALL_SCRIPT} ${WRKSRC}/evilfinder ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
