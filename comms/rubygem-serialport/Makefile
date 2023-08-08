PORTNAME=	serialport
DISTVERSION=	1.3.2
CATEGORIES=	comms rubygems
MASTER_SITES=	RG

MAINTAINER=	tj+freebsd_ports@a13.fr
COMMENT=	Library for using RS-232 serial ports
WWW=		https://rubygems.org/gems/serialport

LICENSE=	GPLv2

USES=		gem shebangfix
SHEBANG_FILES=	test/set_readtimeout.rb

.include <bsd.port.options.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
	@${REINPLACE_CMD} -e 's|-DOS_\#{os.upcase}|-DOS_\#{os.upcase} -Wno-error=int-conversion|g' \
		${WRKSRC}/ext/native/extconf.rb
.endif

.include <bsd.port.mk>
