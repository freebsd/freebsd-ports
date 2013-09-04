# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	namazu
PORTVERSION=	${NAMAZU_PORTVERSION}
CATEGORIES+=	databases www textproc
MASTER_SITES=	http://www.namazu.org/stable/
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-text search system intended for easy use

BUILD_DEPENDS=	p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic
RUN_DEPENDS=	p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic

USES=		gettext iconv perl5
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-perl5="${PERL}" \
		--with-libintl-prefix=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG}
USE_LDCONFIG=	yes

.include "${.CURDIR}/Makefile.common"

MAN1=		namazu.1 mknmz.1

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.css ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.html ${DOCSDIR}/en
	@${MKDIR} ${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/*.html ${DOCSDIR}/ja
.endif

.include <bsd.port.mk>
