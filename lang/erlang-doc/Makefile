# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	r12b1
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://erlang.org/doc/pdf/:release \
		http://erlang.org/download/:erlangorg \
		http://www.erlang.se/doc/:erlangse \
		http://www.sics.se/~joe/thesis/:joe \
		http://www.st.se/telecom/eng/projects/:stse \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=     olgeni/:local
DISTFILES=	appmon.pdf:release \
		asn1.pdf:release \
		common_test.pdf:release \
		compiler.pdf:release \
		cosEvent.pdf:release \
		cosEventDomain.pdf:release \
		cosFileTransfer.pdf:release \
		cosNotification.pdf:release \
		cosProperty.pdf:release \
		cosTime.pdf:release \
		cosTransactions.pdf:release \
		crypto.pdf:release \
		debugger.pdf:release \
		design_principles.pdf:release \
		dialyzer.pdf:release \
		docbuilder.pdf:release \
		edoc.pdf:release \
		efficiency_guide.pdf:release \
		embedded.pdf:release \
		erl_interface.pdf:release \
		erts.pdf:release \
		et.pdf:release \
		getting_started.pdf:release \
		gs.pdf:release \
		ic.pdf:release \
		inets.pdf:release \
		installation_guide.pdf:release \
		inviso.pdf:release \
		jinterface.pdf:release \
		kernel.pdf:release \
		megaco.pdf:release \
		mnesia.pdf:release \
		oam.pdf:release \
		observer.pdf:release \
		odbc.pdf:release \
		orber.pdf:release \
		os_mon.pdf:release \
		otp_mibs.pdf:release \
		parsetools.pdf:release \
		percept.pdf:release \
		pman.pdf:release \
		programming_examples.pdf:release \
		reference_manual.pdf:release \
		runtime_tools.pdf:release \
		sasl.pdf:release \
		snmp.pdf:release \
		ssh.pdf:release \
		ssl.pdf:release \
		stdlib.pdf:release \
		syntax_tools.pdf:release \
		system_architecture_intro.pdf:release \
		system_principles.pdf:release \
		test_server.pdf:release \
		toolbar.pdf:release \
		tools.pdf:release \
		tutorial.pdf:release \
		tv.pdf:release \
		webtool.pdf:release \
		xmerl.pdf:release \
		course.pdf:erlangorg \
		erlang-book-part1.pdf:erlangorg \
		programming_rules.pdf:erlangse \
		armstrong_thesis_2003.pdf:joe \
		master_thesis_patterns.pdf:local
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Documentation (PDF) for the Erlang/OTP system

NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/doc/erlang
.for FILE in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$(expr ${FILE} : '\([^:]*\)') ${LOCALBASE}/share/doc/erlang
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
