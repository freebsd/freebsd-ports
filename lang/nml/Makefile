# Created by: Jaeho Shin <netj@sparcs.kaist.ac.kr>
# $FreeBSD$

PORTNAME=	nml
PORTVERSION=	0.92b
CATEGORIES=	lang
MASTER_SITES=	http://ropas.snu.ac.kr/n/ \
		http://sparcs.kaist.ac.kr/~netj/n/ \
		http://ropas.kaist.ac.kr/n/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dialect/harmony of Standard ML of New Jersey and Objective Caml

WRKSRC=		${WRKDIR}/${PORTNAME}-0.92

ONLY_FOR_ARCHS=	i386
MAKE_JOBS_UNSAFE=	yes
.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN=		ld: error: relocation R_386_PC32 cannot be used against symbol BnnAdd
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix ${PREFIX}

USES=		gmake
ALL_TARGET=	all opt opt.opt
INSTALL_TARGET=	install installopt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e 's|gcc|${CC}|'
	@${REINPLACE_CMD} -e '/freebsd/s/3-9/0-9/; \
		/aspp=/s|gcc|${CC}|; /mksharedlib=/s|gcc|${CC}|' \
		${WRKSRC}/configure

do-install:
	${DO_MAKE_BUILD} -C ${WRKSRC} PREFIX="${STAGEDIR}${PREFIX}" ${INSTALL_TARGET}
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' ${STAGEDIR}${PREFIX}/lib/nml/ld.conf
	@${MKDIR} ${STAGEDIR}${DATADIR}/contrib/emacs
	@${MKDIR} ${STAGEDIR}${DATADIR}/contrib/vim
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/* ${STAGEDIR}${DATADIR}/contrib/emacs
	${INSTALL_DATA} ${WRKSRC}/contrib/vim/* ${STAGEDIR}${DATADIR}/contrib/vim
.for i in ncamlrun nmlc nlex nmakegen nyacc nmlo
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$i
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/LICENSE ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
