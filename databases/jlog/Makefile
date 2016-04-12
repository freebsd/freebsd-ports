# Created by: alfred
# $FreeBSD$

PORTNAME=	jlog
# version is YYYYMMDDxx <- xx is 00, 01 as needed per day
PORTVERSION=	1.2.2.s2015012200
CATEGORIES=	databases

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Journaled log library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	autoconf-2.13:devel/autoconf213

USE_GITHUB=	yes
GH_ACCOUNT=	omniti-labs
# cf3085fe contains c++ fixes and other additions over the 1.2.2 release
GH_TAGNAME=	cf3085f

GNU_CONFIGURE=	yes
USES=		perl5 shebangfix

OPTIONS_DEFINE=		PERL
OPTIONS_DEFAULT=	PERL
OPTIONS_SUB=		yes

SHEBANG_FILES=	jlog_change_endian.pl jlog_sanity_check.pl
perl_OLD_CMD=	/opt/msys/3rdParty/bin/perl

PERL_CONFIGURE_ON=	--with-perl-lib=site
PERL_CONFIGURE_WITH=	perl

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)

.include <bsd.port.mk>
