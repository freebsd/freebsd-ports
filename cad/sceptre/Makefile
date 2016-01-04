# Created by: grog
# $FreeBSD$

PORTNAME=	sceptre
PORTVERSION=	2012.061
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://alpha.fh-friedberg.de/iem/fileadmin/user_upload/novender/sceptre/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General-purpose circuit analysis program

LICENSE=	GPLv2

USES=		fortran

MAKE_JOBS_UNSAFE=	yes
NO_WRKSUBDIR=		yes

FFLAGS+=	-fno-automatic
PORTDOCS=	doc_en.pdf doc_ger.pdf install.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E \
		-e '/^(FC|FFLAGS)[[:blank:]]*=/d' \
		-e 's!/usr/local!${PREFIX}!' \
		-e '/install.*BINDIR/{ s/install -s.*755/${INSTALL_PROGRAM}/ ; \
			s/install -m.*755/${INSTALL_SCRIPT}/ ; }' \
		-e '/install.*(ETCDIR|LIBDIR)/{ /install -d/d ; \
			s/install.*644/${INSTALL_DATA}/ ; }' \
				${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E \
		-e '/^(FC|FFLAGS)[[:blank:]]*=/d' \
		-e 's!ar rv!${AR} ${ARFLAGS}!' \
		-e 's!ranlib!${RANLIB}!' \
				${WRKSRC}/x[123]/Makefile
	@${REINPLACE_CMD} \
		-e 's!/usr/local!${PREFIX}!' \
				${WRKSRC}/bin/ngp \
				${WRKSRC}/bin/sceptre.inst
	@${REINPLACE_CMD} -E \
		-e 's!/usr/local!${PREFIX}!' \
		-e "s!^(FC=')(.*)(')!\1${FC} ${FFLAGS}\3!" \
				${WRKSRC}/bin/sceptre

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/install.pdf ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc ; ${INSTALL_DATA} ${PORTDOCS:Mdoc_*} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC}/samples; for s in ${WRKSRC}/samples/*.d; do \
		${WRKSRC}/bin/sceptre $${s%.d}; \
	done

.include <bsd.port.mk>
