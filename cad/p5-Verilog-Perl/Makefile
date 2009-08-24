# New ports collection makefile for:   Verilog-Perl
# Date created:                11 Apr 2009
# Whom:                        Otacílio de Araújo Ramos Neto <otacilio.neto@ee.ufcg.edu.br>
#
# $FreeBSD$
#

PORTNAME=	Verilog-Perl
PORTVERSION=	3.212
CATEGORIES=	cad perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	otacilio.neto@ee.ufcg.edu.br
COMMENT=	Building point for Verilog support in the Perl language

BUILD_DEPENDS=	flex>=2.5.35:${PORTSDIR}/textproc/flex

USE_GMAKE=	yes
USE_PERL5=	yes
USE_BISON=	build

PERL_CONFIGURE=	yes

MAN1=	vhier.1 vpassert.1 vppreproc.1 vrename.1

MAN3=	Verilog::EditFiles.3 Verilog::Netlist::Logger.3 \
	Verilog::Parser.3 Verilog::Getopt.3 Verilog::Netlist::Module.3 \
	Verilog::Preproc.3 Verilog::Language.3 Verilog::Netlist::Net.3 \
	Verilog::SigParser.3 Verilog::Netlist.3 Verilog::Netlist::Pin.3 \
	Verilog::Netlist::Cell.3 Verilog::Netlist::Port.3 \
	Verilog::Netlist::File.3 Verilog::Netlist::Subclass.3 \
	Verilog::Verilog-Perl.3 Verilog::Netlist::Interface.3 Verilog::Std.3

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/ s/ vsplitmodule//' \
		${WRKSRC}/Makefile.PL

post-build:
	cd ${WRKSRC} && make test

test:
	make post-build

.include <bsd.port.mk>
