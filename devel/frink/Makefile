PORTNAME=	frink
PORTVERSION=	2.2.2p4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://BSDforge.COM/projects/source/devel/frink/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Tcl formatter and static tester
WWW=		https://catless.ncl.ac.uk/Programs/Frink/

LICENSE=	COPYRIGHT
LICENSE_NAME=	The University of Newcastle upon Tyne
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	auto-accept

BROKEN=		Unfetchable

USES=		uidfix

MAKEFILE=	${FILESDIR}/Makefile.bsd

WRKSRC=		${WRKDIR}/${PORTNAME}-2.2.2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=strict-prototypes
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
