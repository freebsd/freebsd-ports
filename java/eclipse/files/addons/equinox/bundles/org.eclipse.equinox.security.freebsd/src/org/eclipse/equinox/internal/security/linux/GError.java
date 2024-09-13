/*******************************************************************************
 * Copyright (c) 2020, 2021 Red Hat Inc.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *     Red Hat Inc. - initial version
 *******************************************************************************/
package org.eclipse.equinox.internal.security.linux;

import java.util.List;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

public class GError extends Structure {
	public int domain;
	public int code;
	public String message;

	public GError(Pointer p) {
		super(p);
		read();
	}

	@Override
	protected List<String> getFieldOrder() {
		return List.of("domain", "code", "message"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
	}
}
