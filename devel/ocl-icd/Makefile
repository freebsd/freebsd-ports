# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ocl-icd
PORTVERSION=	2.2.12
CATEGORIES=	devel
MASTER_SITES=	https://forge.imag.fr/frs/download.php/${REVID}/

MAINTAINER=	ohartmann@walstatt.org
COMMENT=	OpenCL Installable Client Driver

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	opencl>=2.1:devel/opencl

CONFLICTS=	freeocl-[0-9]* opencl-icd-[0-9]*

USES=		gmake libtool localbase:ldflags pathfix

USE_GITHUB=	yes
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
REVID=		836

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=--disable-official-khronos-headers \
		--enable-custom-vendordir \
		--enable-pthread-once

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto \
			asciidoc:textproc/asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${LOCALBASE}/etc/|g' \
		${WRKSRC}/doc/libOpenCL.7.txt.in

.include <bsd.port.mk>
