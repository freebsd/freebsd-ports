# Created by: Frerich Raabe <frerich.raabe@gmx.de>
# $FreeBSD$

PORTNAME=	cmunge
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.vcpc.univie.ac.at/vcpc/jhm/code/ \
		http://bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A tool for encrypting and compacting C source code

WRKSRC=		${WRKDIR}/cmunger
MAKE_ARGS=	CC="${CC} ${CFLAGS}"

PLIST_FILES=	bin/cmunge bin/ctran bin/proc-incl
PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/vcpc_users/jhm/bin/cmunger|${STAGEDIR}${PREFIX}|; \
		s|/usr/ccs/lib/cpp|/usr/bin/cpp|' ${WRKSRC}/cmunge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ctran ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/proc-incl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cmunge ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
