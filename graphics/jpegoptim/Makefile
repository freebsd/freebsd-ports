PORTNAME=	jpegoptim
PORTVERSION=	1.4.7
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility to optimize jpeg files

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		cpe jpeg
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	tjko
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libjpeg=${LOCALBASE}

MAKE_ENV+=	INSTALL_ROOT=${STAGEDIR}

PLIST_FILES=	bin/jpegoptim \
		man/man1/jpegoptim.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|^bindir =.*$$|bindir = @bindir@|g ; \
		 s|^mandir =.*$$|mandir = @mandir@|g ; \
		 s|$$(INSTALL) -m 755|$$(INSTALL_PROGRAM)|g ; \
	         s|$$(INSTALL) -m 644|$$(INSTALL_DATA)|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
