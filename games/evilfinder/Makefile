# New ports collection makefile for:	evilfinder
# Date created:				11 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evilfinder
PORTVERSION=	1.00
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://lcamtuf.coredump.cx/
DISTNAME=	ef
EXTRACT_SUFX=	.tgz

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Numerologically determine the evilness of things

WRKSRC=		${WRKDIR}/${PORTNAME}

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

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|evilnumbers.dat|${DATADIR}/evilnumbers.dat|; \
		s|.tmp-%d-%u|/tmp/.tmp-%d-%u|; \
		s|./shuffle|${PREFIX}/libexec/ef-shuffle|" \
		${WRKSRC}/ef.c
.if !defined(WITHOUT_WRAPPER)
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|/dev/stdin|-stdin|; \
		s|%%LOCALBASE%%|${LOCALBASE}|" \
		${FILESDIR}/evilfinder > ${WRKSRC}/evilfinder
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ef ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shuffle ${PREFIX}/libexec/ef-shuffle
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/evilnumbers.dat ${DATADIR}
.if !defined(WITHOUT_WRAPPER)
	${INSTALL_SCRIPT} ${WRKSRC}/evilfinder ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
