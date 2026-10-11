// Copyright (c) 2026, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef RUNTIME_BIN_PROCESS_SIGNAL_MAP_H_
#define RUNTIME_BIN_PROCESS_SIGNAL_MAP_H_

#include <signal.h>

#include "bin/process.h"

namespace dart {
namespace bin {

// ProcessSignal ids in dart:io use the Linux signal numbers. Systems that
// number signals differently translate them with this function.
// Returns -1 for signals the system does not have.
inline int SignalMap(intptr_t id) {
  switch (static_cast<ProcessSignals>(id)) {
    case kSighup:
      return SIGHUP;
    case kSigint:
      return SIGINT;
    case kSigquit:
      return SIGQUIT;
    case kSigill:
      return SIGILL;
    case kSigtrap:
      return SIGTRAP;
    case kSigabrt:
      return SIGABRT;
    case kSigbus:
      return SIGBUS;
    case kSigfpe:
      return SIGFPE;
    case kSigkill:
      return SIGKILL;
    case kSigusr1:
      return SIGUSR1;
    case kSigsegv:
      return SIGSEGV;
    case kSigusr2:
      return SIGUSR2;
    case kSigpipe:
      return SIGPIPE;
    case kSigalrm:
      return SIGALRM;
    case kSigterm:
      return SIGTERM;
    case kSigchld:
      return SIGCHLD;
    case kSigcont:
      return SIGCONT;
    case kSigstop:
      return SIGSTOP;
    case kSigtstp:
      return SIGTSTP;
    case kSigttin:
      return SIGTTIN;
    case kSigttou:
      return SIGTTOU;
    case kSigurg:
      return SIGURG;
    case kSigxcpu:
      return SIGXCPU;
    case kSigxfsz:
      return SIGXFSZ;
    case kSigvtalrm:
      return SIGVTALRM;
    case kSigprof:
      return SIGPROF;
    case kSigwinch:
      return SIGWINCH;
    case kSigpoll:
      return -1;
    case kSigsys:
      return SIGSYS;
  }
  return -1;
}

}  // namespace bin
}  // namespace dart

#endif  // RUNTIME_BIN_PROCESS_SIGNAL_MAP_H_
