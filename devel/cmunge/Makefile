PORTNAME=	cmunge
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.vcpc.univie.ac.at/vcpc/jhm/code/ \
		http://bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for encrypting and compacting C source code

WRKSRC=		${WRKDIR}/cmunger
MAKE_ARGS=	CC="${CC} ${CFLAGS}"

PLIST_FILES=	bin/cmunge bin/ctran bin/proc-incl
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/vcpc_users/jhm/bin/cmunger|${PREFIX}|; \
		s|/usr/ccs/lib/cpp|/usr/bin/cpp|' ${WRKSRC}/cmunge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ctran ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/proc-incl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cmunge ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
