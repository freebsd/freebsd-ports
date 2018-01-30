# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libasr
PORTVERSION=	201602131606
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
PKGNAMESUFFIX=	-devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Asynchronous DNS resolver library (development snapshot)

LICENSE=	ISCL BSD4CLAUSE BSD3CLAUSE BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENCE

CONFLICTS=	libasr-[0-9]*
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MAN3
OPTIONS_SUB=	yes

MAN3_DESC=	Install API manpages (section 3)
MAN3_USES=	groff
MAN3_CONFIGURE_OFF=	ac_cv_path_GROFF="" ac_cv_path_NROFF="" ac_cv_path_MANDOC=""

USES=		libtool ssl:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
