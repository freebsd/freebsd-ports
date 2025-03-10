PORTNAME=	qrouter
DISTVERSION=	1.4.88
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/${PORTNAME}/archive/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to generate metal layers and vias
WWW=		http://opencircuitdesign.com/qrouter/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gmake localbase tar:tgz tk:87 xorg
USE_XORG=	ice sm x11 xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR}

post-install:
.for f in qrouter.so qrouterexec qrouternullg
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/${f}
.endfor

.include <bsd.port.mk>
