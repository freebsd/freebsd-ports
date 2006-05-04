# ex:ts=8
# New ports collection makefile for:	log4cpp
# Date created:			May 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	log4cpp
PORTVERSION=	0.3.4b
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of C++ classes for flexible logging

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-pthreads --disable-html-docs
MAKE_ENV+=	RM=${RM}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if exists (${LOCALBASE}/bin/doxygen) || !defined (NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen

MAN3=	log4cpp.3 log4cpp::Appender.3 log4cpp::AppenderSkeleton.3\
	log4cpp::BasicConfigurator.3 log4cpp::BasicLayout.3 log4cpp::Category.3\
	log4cpp::CategoryNameComponent.3 log4cpp::CategoryStream.3\
	log4cpp::ConfigureFailure.3 log4cpp::FileAppender.3 log4cpp::Filter.3\
	log4cpp::FixedContextCategory.3 log4cpp::FormatModifierComponent.3\
	log4cpp::HierarchyMaintainer.3 log4cpp::IdsaAppender.3 log4cpp::Layout.3\
	log4cpp::LayoutAppender.3 log4cpp::LoggingEvent.3\
	log4cpp::MessageComponent.3 log4cpp::MillisSinceEpochComponent.3\
	log4cpp::NDC.3 log4cpp::NDC::DiagnosticContext.3 log4cpp::NDCComponent.3\
	log4cpp::NTEventLogAppender.3 log4cpp::OstreamAppender.3\
	log4cpp::PatternLayout.3 log4cpp::PatternLayout::PatternComponent.3\
	log4cpp::Priority.3 log4cpp::PriorityComponent.3\
	log4cpp::ProcessorTimeComponent.3 log4cpp::Properties.3\
	log4cpp::PropertyConfigurator.3 log4cpp::PropertyConfiguratorImpl.3\
	log4cpp::RemoteSyslogAppender.3 log4cpp::RollingFileAppender.3\
	log4cpp::SecondsSinceEpochComponent.3 log4cpp::SimpleConfigurator.3\
	log4cpp::SimpleLayout.3 log4cpp::StringLiteralComponent.3\
	log4cpp::StringQueueAppender.3 log4cpp::StringUtil.3\
	log4cpp::SyslogAppender.3 log4cpp::ThreadNameComponent.3\
	log4cpp::TimeStamp.3 log4cpp::TimeStampComponent.3\
	log4cpp::Win32DebugAppender.3 log4cpp::threading.3\
	log4cpp::threading::MSMutex.3 log4cpp::threading::MSScopedLock.3\
	log4cpp::threading::Mutex.3 log4cpp::threading::ScopedLock.3\
	log4cpp::threading::ThreadLocalDataHolder.3
.else
NOPORTDOCS=		true
CONFIGURE_ARGS+=	--disable-doxygen
.endif

.if !exists (${LOCALBASE}/bin/doxygen) && !defined (NOPORTDOCS)
pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} By default, this port uses doxygen to build its documentation.\
It currently is not present your system, and if you do not want to install it, abort\
this build by hitting CTRL+C and re-run the installation with -DNOPORTDOCS | ${FMT} 74
	@${ECHO_CMD}
	@sleep 3
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
