PORTNAME=	cxref
PORTVERSION=	1.6e
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.gedanken.org.uk/software/cxref/download/ \
		http://fossies.org/linux/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C program cross-referencing and documentation tool
WWW=		https://www.gedanken.org.uk/software/cxref/

LICENSE=	GPLv2

USES=		gmake shebangfix tar:tgz
SHEBANG_FILES=	contrib/xrgr.pl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
ALL_TARGET=	programs

OPTIONS_DEFINE=	CPP
OPTIONS_DEFAULT=
OPTIONS_SUB=yes

CPP_DESC=	with bundled cpp
CPP_CONFIGURE_WITH=	cxref-cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/contrib && ${INSTALL_DATA} *.el *.pl *.py README* \
		${STAGEDIR}${DATADIR})

post-install-CPP-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cxref-cpp

.include <bsd.port.mk>
