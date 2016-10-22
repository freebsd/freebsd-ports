# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ocl-icd
PORTVERSION=	2.2.9
CATEGORIES=	devel
MASTER_SITES=	https://forge.imag.fr/frs/download.php/${REVID}/
REVID=		716

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	OpenCL Installable Client Driver

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	opencl>=2.1:devel/opencl

CONFLICTS=	freeocl-[0-9]* opencl-icd-[0-9]*

USE_RUBY=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
RUBY_NO_RUN_DEPENDS=yes
USES=		gmake libtool localbase pathfix
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=--disable-official-khronos-headers

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto \
			asciidoc:textproc/asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${LOCALBASE}/etc/|g' \
		${WRKSRC}/doc/libOpenCL.7.txt

.include <bsd.port.mk>
