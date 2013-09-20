# Created by: frankch@waru.life.nthu.edu.tw
# $FreeBSD$

PORTNAME=	babel
PORTVERSION=	1.6
PORTREVISION=	4
CATEGORIES=	biology converters
MASTER_SITES=	http://smog.com/chem/babel/files/ \
		http://www.ccl.net/cca/software/UNIX/babel/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts among various molecular file formats

CONFLICTS_INSTALL=	openbabel-*

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES+=	bin/babel libexec/babel
PORTDATA=	element.lis new.lis quanta.lis types.lis
PORTDOCS=	README.1ST

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-build:
	${SED} -e 's%@PREFIX@%${PREFIX}%g' \
		${FILESDIR}/babel.sh >${WRKSRC}/babel.sh

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/babel ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/babel.sh ${PREFIX}/bin/babel
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.lis ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1ST ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
