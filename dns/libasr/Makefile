# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libasr
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Asynchronous DNS resolver library

LICENSE=	ISCL BSD4CLAUSE BSD3CLAUSE BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENCE

CONFLICTS=	libasr-devel-[0-9]*
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MAN3
OPTIONS_SUB=	yes

MAN3_DESC=	Install API manpages (section 3)
MAN3_USES=	groff
MAN3_CONFIGURE_OFF=	ac_cv_path_GROFF="" ac_cv_path_NROFF="" ac_cv_path_MANDOC=""
MAN3_CONFIGURE_ON=	--with-mantype="man"

USES=		libtool ssl:build
USE_LDCONFIG=	yes

CFLAGS+=	-I${OPENSSLINC}

.include <bsd.port.mk>
